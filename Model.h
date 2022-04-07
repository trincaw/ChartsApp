#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "TableData.h"

typedef unsigned int u_int;
using std::vector;

class Model : public QAbstractTableModel
{
    Q_OBJECT
private:
    TableData table;
public:
    Model(QObject *parent = 0);
    TableData getTable() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;



    void readJson(std::string path);
    void writeJson(std::string path);


    void addRow(u_int i, std::string label);
    void addColumn(u_int i, std::string label);
    void removeRow(u_int i);
    void removeColumn(u_int i);
    void newModel(std::string rowLabel, std::string columnLabel);
};

#endif // MODEL_H
