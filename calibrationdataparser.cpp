#include "calibrationdataparser.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QRegularExpression>

CalibrationDataParser::CalibrationDataParser(QObject *parent) : QObject(parent) {}

bool CalibrationDataParser::loadFromFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Failed to open calibration file:" << filePath;
        return false;
    }

    m_matrixData.clear();
    QTextStream in(&file);

    // Skip header row if it exists
    if (!in.atEnd()) {
        QString header = in.readLine();
    }

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

       QStringList parts = line.split(QRegularExpression("[,\\s]+"), Qt::SkipEmptyParts);
        if (parts.size() >= 6) {
            CalibrationRow row;
            row.i = parts[0].toInt();
            row.j = parts[1].toInt();
            row.m = parts[2].toInt();
            row.n = parts[3].toInt();
            row.attn = parts[4].toFloat();
            row.phase = parts[5].toFloat();
            m_matrixData.append(row);
        }
    }

    qDebug() << "Successfully loaded" << m_matrixData.size() << "calibration rows.";
    return true;
}

int CalibrationDataParser::getRowCount() const {
    return m_matrixData.size();
}

CalibrationRow CalibrationDataParser::getRow(int index) const {
    if (index >= 0 && index < m_matrixData.size()) {
        return m_matrixData[index];
    }
    return CalibrationRow{0, 0, 0, 0, 0.0f, 0.0f}; // Fallback
}