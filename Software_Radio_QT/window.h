// Name: Aditi Abhang
// NetID: aaa333

#ifndef WINDOW_H
#define WINDOW_H

#include<QWidget>
#include<QGroupBox>

class QGroupbox;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);

private:
    QGroupBox *StationGroup();
    QGroupBox *SoundSettingGroup();
    QGroupBox *RadioTypeGroup();
    QGroupBox *VolumeGroup();
};

#endif