/****************************************************************************
**
**
****************************************************************************/

#ifndef BASE_MARKET_TREEMODEL_H
#define BASE_MARKET_TREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QtCore>
#include "DataEngine.h"

class CBaseMarketTreeModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    CBaseMarketTreeModel(WORD wMarket,QObject *parent = 0);
    ~CBaseMarketTreeModel();

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

public slots:
	void clearReports();
	bool appendReport(qRcvReportData* data);
	void updateBaseMarket(const QString& qsCode);
//	void resetReports();					//重新更新所有的数据

private:
	WORD m_wMarket;							//该Model表示的股票市场类型
	QStringList m_listHeader;
	QList<qRcvReportData*> m_listItems;
	QMap<QString,int> m_mapTable;			//股票代码和index对照表，方便快速查找
};

#endif	//BASE_MARKET_TREEMODEL_H
