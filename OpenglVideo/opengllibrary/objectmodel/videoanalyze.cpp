#include "videoanalyze.h"


VideoAnalyze::VideoAnalyze(QObject *parent) : QThread(parent)
{

}

VideoAnalyze::~VideoAnalyze()
{

}

void VideoAnalyze::run()
{
    this->readVideo(VIDEO_PATH);
}

bool VideoAnalyze::readVideo(const QString &videoPath)
{
    QMutexLocker mutexLocker(&m_mutex);
    m_videoCapture.open(videoPath.toStdString().c_str());
    if (!m_videoCapture.isOpened()) return false;
    Mat videoFrame;
    while (true)
    {
        m_videoCapture >> videoFrame;
        if (videoFrame.empty()) return false;

        cvtColor(videoFrame, videoFrame, CV_BGR2RGB);
        QImage bufImage = QImage((const unsigned char*)videoFrame.data, videoFrame.cols, videoFrame.rows, videoFrame.cols * videoFrame.channels(), QImage::Format_RGB888);

        emit sendBufImage(bufImage.copy());
        msleep(30);
        waitKey(20);
    }
    m_videoCapture.release();
    return true;
}
