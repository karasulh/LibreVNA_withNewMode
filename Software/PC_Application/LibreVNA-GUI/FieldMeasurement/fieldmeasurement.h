#ifndef FIELDMEASUREMENT_H
#define FIELDMEASUREMENT_H

#include "mode.h"
#include "fieldmeasurementwidget.h"
#include "scpi.h"

class FieldMeasurement : public Mode
{
    Q_OBJECT
public:
    FieldMeasurement(AppWindow *window, QString name = "Field Measurement");
    void deactivate() override;

    void initializeDevice() override;

    virtual Type getType() override { return Type::FM;}

    // Nothing to do for now
    virtual nlohmann::json toJSON() override;
    virtual void fromJSON(nlohmann::json j) override;

    void setAveragingMode(Averaging::Mode mode) override {Q_UNUSED(mode)}

    void preset() override;

    virtual void resetSettings() override;



private slots:
    void updateMeasurement();

private:
    FieldMeasurementWidget *central;

};

#endif // GENERATOR_H
