#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "Table.h"
class Model : public QAbstractTableModel
{
    Q_OBJECT
private:
    Table table;
public:
    Model(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Table getTable() const;

    void readJson(std::string path);
    void writeJson(std::string path);

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    void addRow(unsigned int i, std::string label);
    void addColumn(unsigned int i, std::string label);
    void removeRow(unsigned int i);
    void removeColumn(unsigned int i);
    void newModel(std::string rowLabel, std::string columnLabel);
};

#endif // MODEL_H
