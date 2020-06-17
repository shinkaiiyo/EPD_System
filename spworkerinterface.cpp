#include "spworkerinterface.h"

spworkerinterface::spworkerinterface(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant spworkerinterface::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex spworkerinterface::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex spworkerinterface::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int spworkerinterface::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int spworkerinterface::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant spworkerinterface::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
