#ifndef QSYNTHBUTTONPANEL_H
#define QSYNTHBUTTONPANEL_H

#include "qtogglebutton.h"
#include <QFrame>
#include <QString>
#include "qsynthpanel.h"

namespace Ui {
class QSynthButtonPanel;
}

class QSynthButtonPanel : public QSynthPanel
{
    Q_OBJECT

public:
    QSynthButtonPanel(QWidget *parent = 0);
    void init(const int buttonCount,const QString& parameterName=QString());
    void setValue(const int value);
    int value();
signals:
    void valueChanged(QString name, int value);
private:
    Ui::QSynthButtonPanel *ui;
    QList<QToggleButton*> buttons;
    int m_Value;
    QString m_ParameterName;
private slots:
    void buttonPress();
    void upButtonPress();
    void downButtonPress();
};

#endif
