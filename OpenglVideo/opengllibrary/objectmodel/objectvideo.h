#ifndef OBJECTVIDEO_H
#define OBJECTVIDEO_H
#include "objectparent.h"
#include "videoanalyze.h"

class ObjectVideo : public ObjectParent
{
    Q_OBJECT
public:
    ObjectVideo();
    ~ObjectVideo();
    void makeObject() override;
private slots:
    void receiveBufImage(QImage bufImage);

private:
    void initValue();
    VideoAnalyze m_videoAnalyze;
};

#endif // OBJECTVIDEO_H
