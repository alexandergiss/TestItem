#pragma once

#include <QFutureWatcher>
#include <QMutex>
#include <QPixmap>
#include <QQuickPaintedItem>
#include <QTimer>


class PdfEditorItem : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(QString filepath READ filepath WRITE setFilepath NOTIFY filepathChanged)
    Q_PROPERTY(double contentWidth READ contentWidth WRITE setContentWidth NOTIFY contentWidthChanged)
    Q_PROPERTY(double contentHeight READ contentHeight WRITE setContentHeight NOTIFY contentHeightChanged)

public:
    PdfEditorItem();
    ~PdfEditorItem();
    void paint(QPainter* painter) override;

    QString filepath() const;
    void setFilepath(const QString& path);

    double contentWidth() const;
    void setContentWidth(double value);

    double contentHeight() const;
    void setContentHeight(double value);

    void setZoom(int x, int y, double zoom);
    Q_INVOKABLE void open(const QString& filePath, const QString& password);

signals:
    void filepathChanged(const QString& path);
    void contentWidthChanged(double value);
    void contentHeightChanged(double value);
    void paintSignal();

    void vPositionChanged(double vPos);
    void hPositionChanged(double hPos);

public slots:
    void sizeChanged(int width, int height);
    void vScrollChanged(double vPos);
    void hScrollChanged(double hPos);
    void rotateClockwise();
    void rotateCounterClockwise();
    void setZoom(int percentage);
    void updateScrollBars();

private:
    QFutureWatcher<bool>* fw;

    QPixmap p;
    QMutex mutex;
    QString m_filepath;

    QPoint clickPos;
    QTimer m_timer;
    int m_width;
    int m_height;
    QString m_searchStr;
    bool m_fileOpened;
    QString m_colorScheme;

    static unsigned char* getBmp(const unsigned char* buffer, int width, int height, int stride);
    static void imageCleanupHandler(void* info);
};
