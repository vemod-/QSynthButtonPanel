#include "qsynthbuttonpanel.h"
#include "ui_qsynthbuttonpanel.h"
#include "cresourceinitializer.h"

QSynthButtonPanel::QSynthButtonPanel(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::QSynthButtonPanel)
{
    CResourceInitializer::initializeResources();
    ui->setupUi(this);
    setStyleSheet("QSynthButtonPanel{background-image: url(:/Brushed Aluminium Tile.bmp);border:1px solid #AAAAAA;border-style:outset;border-radius:8px;}");
    connect(ui->upButton,&QAbstractButton::clicked,this,&QSynthButtonPanel::upButtonPress);
    connect(ui->downButton,&QAbstractButton::clicked,this,&QSynthButtonPanel::downButtonPress);
}

void QSynthButtonPanel::init(const int buttonCount,const QString& parameterName)
{
    m_ParameterName=parameterName;
    ui->upButton->setCheckable(false);
    ui->downButton->setCheckable(false);
    for (int i = 0; i < buttonCount; i++)
    {
        auto b = new QToggleButton(this);
        b->setButtonStyle(QToggleButton::TouchStyle);
        QFont f = b->font();
        f.setPointSize(15);
        b->setFont(f);
        b->setText(QString::number(i+1));
        b->setFixedSize(48,48);
        b->setCheckable(true);
        ui->buttonLayout->addWidget(b);
        connect(b,&QAbstractButton::clicked,this,&QSynthButtonPanel::buttonPress);
        buttons.append(b);
    }
    setValue(1);
}

void QSynthButtonPanel::setValue(const int value)
{
    for (int i = 0; i < buttons.size(); i++) buttons[i]->setChecked(i == value -1);
    ui->lcdNumber->display(QString("00" +  QString::number(value)).right(2));
    ui->upButton->setEnabled(value != buttons.size());
    ui->downButton->setEnabled(value != 1);
    m_Value = value;
}

int QSynthButtonPanel::value()
{
    return m_Value;
}

void QSynthButtonPanel::buttonPress()
{
    QPoint p = mapFromGlobal(QCursor::pos());
    for (int i = 0; i < buttons.size(); i++)
    {
        if (buttons[i]->geometry().contains(p))
        {
            setValue(i+1);
            emit valueChanged(m_ParameterName,m_Value);
            return;
        }
    }
}

void QSynthButtonPanel::upButtonPress()
{
    setValue(m_Value + 1);
    emit valueChanged(m_ParameterName,m_Value);
}

void QSynthButtonPanel::downButtonPress()
{
    setValue(m_Value - 1);
    emit valueChanged(m_ParameterName,m_Value);
}
