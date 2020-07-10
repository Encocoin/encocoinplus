// Copyright (c) 2019 The DIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MASTERNODESWIDGET_H
#define MASTERNODESWIDGET_H

#include <QWidget>
#include "qt/epgc/pwidget.h"
#include "qt/epgc/furabstractlistitemdelegate.h"
#include "qt/epgc/mnmodel.h"
#include "qt/epgc/tooltipmenu.h"
#include <QTimer>
#include <atomic>

class EPGCGUI;

namespace Ui {
class MasterNodesWidget;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class MasterNodesWidget : public PWidget
{
    Q_OBJECT

public:

    explicit MasterNodesWidget(EPGCGUI *parent = nullptr);
    ~MasterNodesWidget();

    void loadWalletModel() override;

    void run(int type) override;
    void onError(QString error, int type) override;

    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;

private Q_SLOTS:
    void onCreateMNClicked();
    void onStartAllClicked(int type);
    void changeTheme(bool isLightTheme, QString &theme) override;
    void onMNClicked(const QModelIndex &index);
    void onEditMNClicked();
    void onDeleteMNClicked();
    void onInfoMNClicked();
    void updateListState();
    void updateModelAndInform(QString informText);

private:
    Ui::MasterNodesWidget *ui;
    FurAbstractListItemDelegate *delegate;
    MNModel *mnModel = nullptr;
    TooltipMenu* menu = nullptr;
    QModelIndex index;
    QTimer *timer = nullptr;

    std::atomic<bool> isLoading;

    bool checkMNsNetwork();
    void startAlias(QString strAlias);
    bool startAll(QString& failedMN, bool onlyMissing);
    bool startMN(CMasternodeConfig::CMasternodeEntry mne, std::string& strError);
};

#endif // MASTERNODESWIDGET_H
