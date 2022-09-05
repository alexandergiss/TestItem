#pragma once

#include <QPixmap>
#include <QQuickPaintedItem>

class PdfEditorItem : public QQuickPaintedItem {
    Q_OBJECT

public:
    PdfEditorItem();
    ~PdfEditorItem();

    void paint(QPainter* painter) override;
    Q_INVOKABLE void open(const QString& filePath);

private:
    QPixmap p;
    QString m_filepath;
};
