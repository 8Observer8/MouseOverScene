#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setFixedSize( this->size() );
    connect( ui->widget, SIGNAL( signalCoordinates( QPoint ) ),
             this, SLOT( slotShowCoordinates( QPoint ) ) );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::slotShowCoordinates( const QPoint &p )
{
    ui->xLineEdit->setText( QString::number( p.x() ) );
    ui->yLineEdit->setText( QString::number( p.y() ) );
}

