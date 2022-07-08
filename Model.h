#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <QTextStream>
#include <QtXml>
#include <iostream>
#include <fstream>



#include "TableData.h"

typedef unsigned int u_int;
using std::vector;
using std::string;

class Model : public QAbstractTableModel
{
    Q_OBJECT
private:
    TableData *table=nullptr;
public:
    Model(QObject *parent = 0);
    TableData* getTable();
    ~Model();

    //implementation of QAbstractTableModel on Table data
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    //basic operation on the table
    void addRow(u_int index, string label);
    void addColumn(u_int index, string label);
    void removeRow(u_int index);
    void removeColumn(u_int index);

    //xml read/write
    void createNewTable();
    void SaveCSV(QString path) const;
    void LoadCSV(QString path);
    void SaveXML(QString path) const;
    void LoadXML(QString path);

};

#endif // MODEL_H
