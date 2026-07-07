#ifndef CALIBRATIONDATAPARSER_H
#define CALIBRATIONDATAPARSER_H

#include <QObject>
#include <QVector>
#include <QString>

// Represents a single row from the mentor's sketched matrix
struct CalibrationRow {
    int i;
    int j;
    int m;
    int n;
    float attn;
    float phase;
};

class CalibrationDataParser : public QObject {
    Q_OBJECT
public:
    explicit CalibrationDataParser(QObject *parent = nullptr);

    bool loadFromFile(const QString& filePath);
    int getRowCount() const;
    CalibrationRow getRow(int index) const;

private:
    QVector<CalibrationRow> m_matrixData;
};

#endif // CALIBRATIONDATAPARSER_H