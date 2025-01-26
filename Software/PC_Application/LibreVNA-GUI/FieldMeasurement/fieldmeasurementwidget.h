#ifndef FIELDMEASUREMENTWIDGET_H
#define FIELDMEASUREMENTWIDGET_H

#include "savable.h"
#include "appwindow.h"

#include <QWidget>

namespace Ui {
class FieldMeasurementWidget;
}

class FieldMeasurementWidget : public QWidget, public Savable
{
    Q_OBJECT

public:
    explicit FieldMeasurementWidget(AppWindow *window, QWidget *parent = nullptr);
    ~FieldMeasurementWidget();

    virtual nlohmann::json toJSON() override;
    virtual void fromJSON(nlohmann::json j) override;


signals:
    void SettingsChanged();

public slots:
    void setPeriod(double period);

protected:
    void timerEvent(QTimerEvent *) override;

private:
    Ui::FieldMeasurementWidget *ui;
    int m_timerId;
    AppWindow *window;
};

#endif // FieldMeasurementWidget
