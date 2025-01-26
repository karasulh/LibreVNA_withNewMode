#include "fieldmeasurement.h"

#include "CustomWidgets/informationbox.h"

#include <QSettings>

FieldMeasurement::FieldMeasurement(AppWindow *window, QString name)
    : Mode(window, name, "Field Measurement")
{
    central = new FieldMeasurementWidget(window, window);

    // set initial values
    central->setPeriod(0);

    finalize(central);
    connect(central, &FieldMeasurementWidget::SettingsChanged, this, &FieldMeasurement::updateSettings);
    connect(central, &FieldMeasurementWidget::TimerUp, this, &FieldMeasurement::updateTimerUp);
}

void FieldMeasurement::updateSettings(){

}

void FieldMeasurement::updateTimerUp(){
    //RUN Export Function
}

void FieldMeasurement::initializeDevice()
{
    updateSettings();
}

nlohmann::json FieldMeasurement::toJSON()
{
    return central->toJSON();
}

void FieldMeasurement::fromJSON(nlohmann::json j)
{
    if(j.is_null()) {
        return;
    }
    central->fromJSON(j);
}

void FieldMeasurement::preset()
{

}

void FieldMeasurement::deactivate()
{
    Mode::deactivate();
}


void FieldMeasurement::resetSettings()
{
    central->setPeriod(0);
}


