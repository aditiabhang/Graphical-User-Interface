/*

 Name:  Aditi Abhang
 NetID: aaa333

*/

#include<QtGui>
#include<Qt>
#include "window.h"
#include "globj.h"
#include "tetrahedron.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{   
    //Creating a grid layout to arrange 4 groups
    QGridLayout *grid = new QGridLayout;    
    grid->addWidget(StationGroup(), 0, 0);
    grid->addWidget(SoundSettingGroup(), 1, 0);
    grid->addWidget(RadioTypeGroup(), 0, 1);
    grid->addWidget(VolumeGroup(), 1, 1);
    
    // Calling the Globj object & Tetrahedron object
    GLobj *globj = new GLobj;
    Tetrahedron *tetra = new Tetrahedron;

    // using Dock Widget for merging
    QDockWidget *dock = new QDockWidget(); 
    dock->setWidget(globj);

    QDockWidget *dockTetra = new QDockWidget(); 
    dockTetra->setWidget(tetra);

    //-------
    // QDockWidget *shapesDock = new QDockWidget(tr("QDW1"), this);
    // addDockWidget(Qt::RightDockWidgetArea, dwidget);
    // QDockWidget *dwidget2 = new QDockWidget(tr("QDW2"), this);
    // splitDockWidget(dwidget, dwidget2, Qt::Horizontal);
    //---

    QHBoxLayout *shapeLayout= new QHBoxLayout;
    shapeLayout-> addWidget(dock);
    shapeLayout-> addLayout(grid);
    shapeLayout-> addWidget(dockTetra);
    setLayout(shapeLayout);

    setWindowTitle(tr("!!...Awesome Docksome Software Radio & Shapes...!!"));
    resize(950, 500);
}
// Group box 1 : Station label and LCD 
QGroupBox *Window::StationGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Frequency Tuner"));
    
    // creating label Station
    QLabel *labelStation = new QLabel();
    labelStation->setText("Station");
    
    // creating LCD display
    QLCDNumber *lcd = new QLCDNumber(3);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->display(101); // adding lcd value (update)
    
    // Horizontal layout for station label and lcd display
    QHBoxLayout *stationlcdbox = new QHBoxLayout;
    stationlcdbox->addWidget(labelStation);
    stationlcdbox->addWidget(lcd);
    
    // creating dial for tuner
    QDial *dial = new QDial();
    dial->setRange(90,450);
    dial->setValue(101);
    
    //making connection between dial and lcd display
    QObject::connect(dial,SIGNAL(valueChanged(int)),lcd,SLOT(display(int)));
    
    // Vertical layout for dial 
    QVBoxLayout *dialLayout = new QVBoxLayout;
    dialLayout->addLayout(stationlcdbox);
    dialLayout->addWidget(dial);
    
    groupBox->setLayout(dialLayout);

    return groupBox;
}   
// Group box 2 : Sound settings for Bass and Treble
QGroupBox *Window::SoundSettingGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Sound Settings"));

    // creating label for Bass and Treble
    QLabel *labelBass = new QLabel;
    labelBass->setText("Bass");
    QLabel *labelTreble = new QLabel;
    labelTreble->setText("Treble");
    
    // creating horizontal slider for Bass and Treble
    QSlider *sliderBass = new QSlider(Qt::Horizontal);
    QSlider *sliderTreble = new QSlider(Qt::Horizontal);

    // creating a spinbox to display the bass and treble
    QSpinBox *spinBoxBass = new QSpinBox;
    QSpinBox *spinBoxTreble = new QSpinBox;

    // making connection of bass and treble slider to their spinboxes
    QObject::connect(spinBoxBass,SIGNAL(valueChanged(int)),sliderBass,SLOT(setValue(int)));
    QObject::connect(sliderBass,SIGNAL(valueChanged(int)),spinBoxBass,SLOT(setValue(int)));
    QObject::connect(spinBoxTreble,SIGNAL(valueChanged(int)),sliderTreble,SLOT(setValue(int)));
    QObject::connect(sliderTreble,SIGNAL(valueChanged(int)),spinBoxTreble,SLOT(setValue(int)));

    // creating horizontal layout for the bass and the treble label with their spinboxes
    QHBoxLayout *soundBassLayout =  new QHBoxLayout;
    soundBassLayout->addWidget(labelBass);
    soundBassLayout->addWidget(spinBoxBass);

    QHBoxLayout *soundTrebleLayout =  new QHBoxLayout;
    soundTrebleLayout->addWidget(labelTreble);
    soundTrebleLayout->addWidget(spinBoxTreble);


    // creating vertical layout for the bass and treble
    QVBoxLayout *soundLayout =  new QVBoxLayout;
    soundLayout->addLayout(soundBassLayout);
    soundLayout->addWidget(sliderBass);
    soundLayout->addLayout(soundTrebleLayout);
    soundLayout->addWidget(sliderTreble);

    // setting range and value for bass and treble
    sliderBass->setRange(0,100);
    sliderBass->setValue(10);
    sliderTreble->setRange(0,100);
    sliderTreble->setValue(6);
    
    groupBox->setLayout(soundLayout);

    return groupBox;
} 
// Group box 3 : Radio types (AM, FM, SAT)
QGroupBox *Window::RadioTypeGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Modulation"));

    // creating label for AM, FM and SAT
    QLabel *labelAM = new QLabel;
    labelAM->setText("AM");
    QLabel *labelFM = new QLabel;
    labelFM->setText("FM");
    QLabel *labelSAT = new QLabel;
    labelSAT->setText("SAT");

    // Setting boolean value for AM,FM and SAT
    QRadioButton *buttonAM = new QRadioButton;
    buttonAM->setChecked(false);
    QRadioButton *buttonFM = new QRadioButton;
    buttonFM->setChecked(true);
    QRadioButton *buttonSAT = new QRadioButton;
    buttonSAT->setChecked(false);

    // creating horizontal layout for AM,FM, and SAT
    QHBoxLayout *RadioTypeLayout = new QHBoxLayout;
    RadioTypeLayout->addWidget(labelAM);
    RadioTypeLayout->addWidget(buttonAM);
    RadioTypeLayout->addWidget(labelFM);
    RadioTypeLayout->addWidget(buttonFM);
    RadioTypeLayout->addWidget(labelSAT);
    RadioTypeLayout->addWidget(buttonSAT);

    groupBox->setLayout(RadioTypeLayout);

    return groupBox;
    
}
// Group box 4 : Volume and Quit
QGroupBox *Window::VolumeGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Volume"));

    // creating label for volume
    QLabel *labelVolume = new QLabel;
    labelVolume->setText("Volume");

    // creating vertical slider and spinbox for volume
    QSlider *sliderVolume = new QSlider(Qt::Horizontal);
    QSpinBox *spinBoxVolume = new QSpinBox;

    // creating push button for quit
    QPushButton *quit = new QPushButton(); 
    quit->setText("Quit");

    //Note to rotate Tetrahedron
    QLabel *tetra_note = new QLabel;
    tetra_note->setStyleSheet("color: blue; background-color: yellow");
    tetra_note->setText("PS: Please use your curser to move the Tetrahedron --->");
    //Label to change Tetrahedron color
    QLabel *tetra_color = new QLabel;
    tetra_color->setStyleSheet("color: blue; background-color: yellow");
    tetra_color->setText("Double-click to select side & change it\'s color!!");

    QLabel *credits = new QLabel;
    credits->setStyleSheet("text-align: right, background-color: beige");
    credits->setText("@Aditi_Abhang");

    // making connect for the quit button
    //QObject::connect(quit,SIGNAL(clicked()),window,SLOT(close()));

    // setting range for volume spinbox and slider
    spinBoxVolume->setRange(0,100);
    sliderVolume->setRange(0,100);

    // setting volume value
    sliderVolume->setValue(10);
    spinBoxVolume->setValue(10);

    // making connection between spinbox and slider of volume
    QObject::connect(spinBoxVolume,SIGNAL(valueChanged(int)),sliderVolume,SLOT(setValue(int)));
    QObject::connect(sliderVolume,SIGNAL(valueChanged(int)),spinBoxVolume,SLOT(setValue(int)));

    // creating horizontal layout for Volume
    QHBoxLayout *VolumeLayout = new QHBoxLayout;
    VolumeLayout->addWidget(sliderVolume);
    VolumeLayout->addWidget(spinBoxVolume);

    // creating vertical layout for the above volume layout and quit button
    QVBoxLayout *VolumeInfoLayout = new QVBoxLayout;
    VolumeInfoLayout->addLayout(VolumeLayout);
    VolumeInfoLayout->addStretch(2);
    VolumeInfoLayout->addWidget(tetra_note);
    VolumeInfoLayout->addWidget(tetra_color);
    VolumeInfoLayout->addStretch(1);
    VolumeInfoLayout->addWidget(quit);
    VolumeInfoLayout->addWidget(credits);

    groupBox->setLayout(VolumeInfoLayout);

    return groupBox;
} 

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}


    



 