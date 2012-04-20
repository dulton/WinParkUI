#include "Header/access2records.h"
#include "ui_access2records.h"
#include "Common/commonfunction.h"
#include "Common/logicinterface.h"
#include "Header/picturescale.h"
#include "Dialog/dlggarageingarage.h"

CAccess2Records::CAccess2Records(QWidget* mainWnd, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CAccess2Records)
{
    ui->setupUi(this);
    pParent = dynamic_cast< MainWindow* > ( mainWnd );
    CCommonFunction::ConnectCloseButton( ui->lblClose );

    ControlDataGrid( );
    ui->lblTitle->setText( windowTitle( ) );

    lblImage[ 0 ] = ui->lblImg0;
    lblImage[ 1 ] = ui->lblImg1;
    lblImage[ 2 ] = ui->lblImg2;
    lblImage[ 3 ] = ui->lblImg3;
    lblImage[ 4 ] = ui->lblImg4;
    lblImage[ 5 ] = ui->lblImg5;
    lblImage[ 6 ] = ui->lblImg6;
    lblImage[ 7 ] = ui->lblImg7;

    gbImage[ 0 ] = ui->gb0;
    gbImage[ 1 ] = ui->gb1;
    gbImage[ 2 ] = ui->gb2;
    gbImage[ 3 ] = ui->gb3;
    gbImage[ 4 ] = ui->gb4;
    gbImage[ 5 ] = ui->gb5;
    gbImage[ 6 ] = ui->gb6;
    gbImage[ 7 ] = ui->gb7;

    cbxQuery[ 0 ] = ui->cb0;
    cbxQuery[ 1 ] = ui->cb1;
    cbxQuery[ 2 ] = ui->cb2;
    cbxQuery[ 3 ] = ui->cb3;
    cbxQuery[ 4 ] = ui->cb4;
    cbxQuery[ 5 ] = ui->cb5;
    cbxQuery[ 6 ] = ui->cb6;
    cbxQuery[ 7 ] = ui->cb7;
    cbxQuery[ 8 ] = ui->cb8;

    QRect rect;
    rect.setX( 10 );
    rect.setY( 20 );
    rect.setWidth( 251 );
    rect.setHeight( 251 );

    for ( int nIndex = 0; nIndex < 8; nIndex++ ) {
        lblImage[ nIndex ]->setVisible( false );
        lblScaleImage[ nIndex ] = new CPictureScale( nIndex, rect,
                                                                              this, gbImage[ nIndex ] );
        connect( lblScaleImage[ nIndex ], SIGNAL( HideCtrl( bool ) ), this, SLOT( HideCtrl( bool ) ) );
    }

    InitQuery( );
}

void CAccess2Records::HideCtrl( bool bVisible )
{
    ui->widget->setVisible( bVisible );
}

CAccess2Records::~CAccess2Records()
{
    delete ui;
}

void CAccess2Records::ControlDataGrid( )
{
    int nIndex = 0;
    QHeaderView* pHeader = ui->tableAccessRecord->horizontalHeader( );
    nIndex = 7;
    pHeader->resizeSection( nIndex, pHeader->sectionSize( nIndex ) * 2 );
    nIndex = 9;
    pHeader->resizeSection( nIndex, pHeader->sectionSize( nIndex ) * 2 );
}

void CAccess2Records::closeEvent( QCloseEvent *event )
{
    pParent->ControlChild( event, this );
}

void CAccess2Records::FillTable( QString& strWhere )
{
    CCommonFunction::FreeAllRows( ui->tableAccessRecord );

    QStringList lstData;
    int nCols = 13;
    int nRows; // = CLogicInterface::GetInterface( )->OperateOutInInfo( lstData, CommonDataType::SelectData, strWhere );

    QString strSql = QString( "select a.cardno, a.cardkind, a.feenum, a.feefactnum, a.feezkyy, a.cardselfno, \
            a.inshebeiname, a.intime, a.outshebeiname, a.outtime, a.carkind, a.carcp, a.carcpout from stoprd a " ).arg( strWhere );

    nRows = CLogicInterface::GetInterface( )->ExecuteSql( strSql, lstData, CCommonFunction::GetHistoryDb( ) );

    ui->tableAccessRecord->setRowCount( nRows );

    for ( int nRow = 0; nRow < nRows; nRow++ ) {
        for ( int nCol = 0; nCol < nCols; nCol++ ) {
            QTableWidgetItem* pItem = new QTableWidgetItem( lstData[ nRow * nCols + nCol ]);
            ui->tableAccessRecord->setItem( nRow, nCol, pItem );
            pItem->setFlags( Qt::ItemIsEnabled | Qt::ItemIsSelectable );
        }
    }
}

void CAccess2Records::resizeEvent( QResizeEvent* )
{
    //FillTable( );
    CalculatePos( );
}

void CAccess2Records::showEvent(QShowEvent *)
{
    //FillTable( );
}

void CAccess2Records::CalculatePos( )
{
    move( 23, 55 );
    return;
    QRect rectWnd = this->geometry( );

    QString strName = "widget";
    QWidget* pWg = findChild< QWidget* >( strName );
    QRect rectWg = pWg->geometry( );
    pWg->setGeometry( ( rectWnd.width( ) - rectWg.width( ) -2 ) / 2,
                      ( rectWnd.height( )  - rectWg.height( ) -2 ) / 2,
                      rectWg.width( ), rectWg.height( ) );
}

void CAccess2Records::on_btnMinimalize_clicked()
{
    setVisible( false );
    pParent->ControlMonitor( true );
}

void CAccess2Records::GetImage( CommonDataType::BlobType blob, int nRow )
{

    QSettings* pSystemSet = CCommonFunction::GetSettings( CommonDataType::CfgSystem );
    pSystemSet->sync( );
    QString strWhere;

    bool bSenseOpenGate = pSystemSet->value( "CommonCfg/SenseOpenGate", false ).toBool( );
    if ( bSenseOpenGate ) {
        strWhere = QString( " Where cardno = '%1'" ).arg( ui->tableAccessRecord->item( nRow, 0 )->text( ) );
    } else {
        strWhere = QString( " Where cardno = '%1' and inshebeiname = '%2' and intime = '%3'" ).arg(
                                ui->tableAccessRecord->item( nRow, 0 )->text( ),
                                ui->tableAccessRecord->item( nRow, 6 )->text( ),
                                ui->tableAccessRecord->item( nRow, 7 )->text( ) );
    }
    QLabel* pLbl = lblScaleImage[ blob ];

    CCommonFunction::LoadFourImages( blob, strWhere, *pLbl, CCommonFunction::GetHistoryDb( ) );
}

void CAccess2Records::on_tableAccessRecord_cellClicked(int row, int column)
{
    for ( int nIndex = 0; nIndex < 8; nIndex++ ) {
        GetImage( ( CommonDataType::BlobType ) nIndex, row );
    }
}

void CAccess2Records::on_lblClose_linkActivated(QString)
{
    close( );
}

void CAccess2Records::on_tableAccessRecord_cellDoubleClicked(int row, int )
{
    QTableWidget* tab = ui->tableAccessRecord;
    QString strImagePath;
    CCommonFunction::GetPath( strImagePath, CommonDataType::PathUIImage );
    strImagePath +="NewIcon/CommonMiddleBG-normal.jpg";

    QString strWhere = QString( " Where CardId = '%1' " ).arg( tab->item( row, 0 )->text( ) );
    CDlgGarageInGarage dlg;
    dlg.setStatusTip( strImagePath );
    if ( dlg.FillTable( strWhere ) ) {
        dlg.exec( );
    } else {
        CCommonFunction::MsgBox( NULL, "��ʾ", "�˳������ӿ��¼��", QMessageBox::Information );
    }
}

void CAccess2Records::GetWhere( QString &strWhere )
{
    QString strText = "";
    strWhere = "";

    for ( uint nSection = 0; nSection < sizeof ( cbxQuery ) / sizeof ( QComboBox* ); nSection++ ) {
        strText = cbxQuery[ nSection ]->currentText( );

        if ( strText.isEmpty( ) || "��" == strText ) {
            continue;
        }

        strText = cbxQuery[ nSection ]->statusTip( ).arg( strText );
        if ( strWhere.isEmpty( ) ) {
            strWhere = strText;
        } else {
            strWhere += " And " + strText;
        }
    }

    if ( !strWhere.isEmpty( ) ) {
        strWhere = " Where " + strWhere;
    }
}

void CAccess2Records::on_btnQuery_clicked()
{
    QString strWhere = "";
    GetWhere( strWhere );

    if ( strWhere.isEmpty( ) ) {
        CCommonFunction::MsgBox( NULL, "��ʾ", "�������ѯ������", QMessageBox::Information );
        return;
    }
    FillTable( strWhere );
}

void CAccess2Records::InitQuery( )
{
    ui->label_2->setVisible( false );
    ui->cb1->setVisible( false );
    ui->label_3->setVisible( false );
    ui->cb2->setVisible( false );
    return;
    QDateTime dtCurrent = QDateTime::currentDateTime( );
    dtCurrent = dtCurrent.addMonths( -1 );
    QString strDateTime;
    CCommonFunction::DateTime2String( dtCurrent, strDateTime );

    QString strSql = QString( "select '��' from dual \
            union all \
            select distinct cardno from stoprd  where cardno is not null \
            union all \
            select 'end' from dual \
            union all \
            select '��' from dual \
            union all \
            select distinct cardkind from stoprd where cardkind is not null \
            union all \
            select 'end' from dual \
            union all \
            select '��' from dual \
            union all \
            select distinct cardselfno from stoprd where cardselfno is not null \
            union all \
            select 'end' from dual \
            union all \
            select '��' from dual \
            union all \
            select distinct inshebeiname from stoprd where inshebeiname is not null \
            union all \
            select 'end' from dual \
            union all \
            select '��' from dual \
            union all \
            select distinct outshebeiname from stoprd where outshebeiname is not null \
            union all \
            select 'end' from dual \
            union all \
            select '��' from dual \
            union all \
            select distinct intime from stoprd where intime >= '%1' \
            union all \
            select 'end' from dual \
            union all \
            select '��' from dual \
            union all \
            select distinct outtime from stoprd where outtime  >= '%2' \
            union all \
            select 'end' from dual \
            union all \
            select '��' from dual \
            union all \
            select distinct carcp from stoprd where carcp is not null \
            union all \
            select 'end' from dual \
            union all \
            select '��' from dual \
            union all \
            select distinct carcpout from stoprd where carcpout is not null" ).arg( strDateTime, strDateTime );


        QStringList lstRows;
        CLogicInterface::GetInterface( )->ExecuteSql( strSql, lstRows );

        QString strSeperator = ",";
        QString strEnd = ",end,";
        QString strRows = lstRows.join( strSeperator );

        QStringList lstValues = strRows.split( strEnd );
        QStringList lstTmp;

        for ( uint nSection = 0; nSection < sizeof ( cbxQuery ) / sizeof ( QComboBox* ); nSection++ ) {
            lstTmp = lstValues.at( nSection ).split( strSeperator );
            cbxQuery[ nSection ]->addItems( lstTmp );
        }
}