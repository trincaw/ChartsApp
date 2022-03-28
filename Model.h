#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "TableData.h"

typedef unsigned int u_int;
using std::vector;
using std::string;

class Model : public QAbstractTableModel
{
    Q_OBJECT
private:
    TableData table;
public:
    Model(QObject *parent = 0);
    TableData getTable() const;
    void setTable(TableData table);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    void readJson(string path);
    void writeJson(string path);

    void addRow(u_int index, string label);
    void addColumn(u_int index, string label);
    void removeRow(u_int index);
    void removeColumn(u_int index);
    void newModel(string rowLabel, string columnLabel);
};

#endif // MODEL_H
