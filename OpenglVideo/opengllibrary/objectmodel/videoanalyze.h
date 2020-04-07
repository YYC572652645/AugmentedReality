#ifndef VIDEOANALYZE_H
#define VIDEOANALYZE_H

#include <QThread>
#include <QImage>
#include <QMutex>
#include<opencv2/opencv.hpp>

using namespace cv;

class VideoAnalyze : public QThread
{
    Q_OBJECT
public:
    explicit VideoAnalyze(QObject *parent = 0);
    ~VideoAnalyze();
    void run() override;
signals:
    void sendBufImage(QImage);
private:
    bool readVideo(const QString &videoPath);
private:
    VideoCapture m_videoCapture;
    QMutex m_mutex;
private:
    const QString VIDEO_PATH = "camera.mp4";
};

#endif // VIDEOANALYZE_H
