#include "PdfEditorItem.h"

#include <QPainter>

PdfEditorItem::PdfEditorItem() : QQuickPaintedItem() {
    setAntialiasing(true);
}

PdfEditorItem::~PdfEditorItem() {
}

void PdfEditorItem::paint(QPainter* painter) {
    p.load(m_filepath);
    painter->drawPixmap(0, 0, p);
}

void PdfEditorItem::open(const QString& filepath) {
    m_filepath = filepath;
}
