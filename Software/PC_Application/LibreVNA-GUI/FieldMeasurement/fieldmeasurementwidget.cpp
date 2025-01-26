#include "fieldmeasurementwidget.h"

#include "ui_fieldmeasurementwidget.h"

FieldMeasurementWidget::FieldMeasurementWidget(AppWindow *window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FieldMeasurementWidget),
    m_timerId(0),
    window(window)
{
    ui->setupUi(this);
    ui->period->setUnit("second");
    ui->period->setPrefixes(" s");
    ui->period->setPrecision(1); // show enough digits


    connect(ui->period, &SIUnitEdit::valueChanged, [=](double newval) {
       if(newval < 0) {
           newval = 0;
       }
       ui->period->setValueQuiet(newval);
       emit SettingsChanged();
    });


   setPeriod(ui->period->value());

}


FieldMeasurementWidget::~FieldMeasurementWidget()
{
    delete ui;
}

void FieldMeasurementWidget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timerId) {
        emit TimerUp();
    }
}


void FieldMeasurementWidget::setPeriod(double period)
{

    if(period < 0) {
        period = 0;
    }

    ui->period->setValue(period);
}

nlohmann::json FieldMeasurementWidget::toJSON()
{
    nlohmann::json j;
    return j;
}

void FieldMeasurementWidget::fromJSON(nlohmann::json j)
{

}



