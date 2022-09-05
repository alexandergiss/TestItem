#include "PdfEditorItem.h"

#include <QClipboard>
#include <QDesktopServices>
#include <QPainter>
#include <QPainterPath>
#include <QtConcurrent/QtConcurrent>


PdfEditorItem::PdfEditorItem() : QQuickPaintedItem() {
    m_fileOpened = false;

    setAntialiasing(true);

    connect(this, &PdfEditorItem::paintSignal, this, [=] {
        update();
    });

    setFlags(flags() | QQuickItem::ItemIsFocusScope);
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::LeftButton | Qt::RightButton | Qt::MiddleButton);

    m_timer.setInterval(50);
    m_timer.setSingleShot(true);
}

PdfEditorItem::~PdfEditorItem() {
}

void PdfEditorItem::updateScrollBars() {
    emit contentHeightChanged(contentHeight());
    emit contentWidthChanged(contentWidth());
}

void PdfEditorItem::imageCleanupHandler(void* info) {
    free(info);
}

void PdfEditorItem::paint(QPainter* painter) {
    mutex.lock();
    painter->drawPixmap(0, 0, p);

    painter->setCompositionMode(QPainter::CompositionMode_Multiply);

    QPainterPath painterPath;
    painterPath.setFillRule(Qt::WindingFill);

    //foreach (tRectOnPage r, selectionRects) {
    //    QRect rect = rectOnPageToQRect(r);
    //    painterPath.addRect(rect);
   // }

    //painter->fillPath(painterPath, SELECTION_COLOR);
    mutex.unlock();
}

void PdfEditorItem::open(const QString& filePath, const QString& password) {
    try {
        m_fileOpened = true;
    } catch (std::exception e) {
        m_filepath = "";
        m_fileOpened = false;
    }
}

void PdfEditorItem::setZoom(int percentage) {
    //view->SetZoom(percentage / 100.0);
    updateScrollBars();
}

void PdfEditorItem::setZoom(int x, int y, double zoom) {
    //view->SetZoom(x, y, zoom);
}

unsigned char* PdfEditorItem::getBmp(const unsigned char* buffer, int width, int height, int stride) {
    /*int bmpLength = BMP_DATA_OFFSET + stride * height;
    unsigned char* bmp = (unsigned char*) malloc(bmpLength * sizeof(unsigned char));

    unsigned char bmpHeader[BMP_HEADER_LENGTH] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, BMP_DATA_OFFSET, 0, 0, 0 };
    bmpHeader[2] = (unsigned char) bmpLength;
    bmpHeader[3] = (unsigned char) (bmpLength >> 8);
    bmpHeader[4] = (unsigned char) (bmpLength >> 16);
    bmpHeader[5] = (unsigned char) (bmpLength >> 24);

    unsigned char bmpInfoHeader[BMP_INFO_HEADER_LENGTH] = { BMP_INFO_HEADER_LENGTH, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, PLANES_, 0, BITS_PER_PIXEL, 0 };
    bmpInfoHeader[4] = (unsigned char) width;
    bmpInfoHeader[5] = (unsigned char) (width >> 8);
    bmpInfoHeader[6] = (unsigned char) (width >> 16);
    bmpInfoHeader[7] = (unsigned char) (width >> 24);

    bmpInfoHeader[8] = (unsigned char) height;
    bmpInfoHeader[9] = (unsigned char) (height >> 8);
    bmpInfoHeader[10] = (unsigned char) (height >> 16);
    bmpInfoHeader[11] = (unsigned char) (height >> 24);

    for (int i = 0; i < BMP_HEADER_LENGTH; i++) {
        bmp[i] = bmpHeader[i];
    }

    for (int i = 0; i < BMP_INFO_HEADER_LENGTH; i++) {
        bmp[BMP_HEADER_LENGTH + i] = bmpInfoHeader[i];
    }

    int k = 0;

    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < stride; j++) {
            bmp[BMP_DATA_OFFSET + k++] = buffer[i * stride + j];
        }
    }

    return bmp;*/
}

QString PdfEditorItem::filepath() const {
    return m_filepath;
}

void PdfEditorItem::setFilepath(const QString& path) {
    if (path.isEmpty())
        return;

    int i = 0;

    if (path.startsWith("file:")) {
        i = path.indexOf("/");

        while (path[i] == '/') {
            i++;
        }
    }

    m_filepath = path.mid(i);

    open(m_filepath, "");
}

void PdfEditorItem::sizeChanged(int width, int height) {
    m_timer.start();
    m_width = width;
    m_height = height;
}

void PdfEditorItem::vScrollChanged(double vPos) {
}

void PdfEditorItem::hScrollChanged(double hPos) {
}

void PdfEditorItem::rotateClockwise() {
}

void PdfEditorItem::rotateCounterClockwise() {
}

double PdfEditorItem::contentWidth() const {
    return 0;
}

void PdfEditorItem::setContentWidth(double value) {

}

double PdfEditorItem::contentHeight() const {
    return 0;
}

void PdfEditorItem::setContentHeight(double value) {

}

