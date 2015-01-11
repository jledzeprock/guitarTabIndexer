#include "guitartab.h"

GuitarTab::GuitarTab()
{

}

GuitarTab::GuitarTab(const GuitarTab &another) : bandName(another.bandName),
    songTitle(another.songTitle), tabPath(another.tabPath) , summary(another.summary), extension(another.extension)
{

}

GuitarTab::~GuitarTab()
{
}



QString GuitarTab::getBandName() const
{
    return bandName;
}

QString GuitarTab::getSongTitle() const
{
    return songTitle;
}

QString GuitarTab::getTabPath() const
{
    return tabPath;
}

QString GuitarTab::getSummary() const
{
    return summary;
}

QString GuitarTab::getExtension() const
{
    return extension;
}

void GuitarTab::setExtension(QString value)
{
    this->extension = value;
}

void GuitarTab::setBandName(QString value)
{
    bandName = value;
}

void GuitarTab::setSongTitle(QString value)
{
    songTitle = value;
}

void GuitarTab::setTabPath(QString value)
{
    tabPath = value;
}

void GuitarTab::setSummary(QString desc)
{
    summary = desc;
}

void GuitarTab::initSummary()
{
    summary = bandName + " " + songTitle;
}

