// Copyright (c) 2017-2019 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZEPGCONTROLDIALOG_H
#define ZEPGCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zepg/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZEpgControlDialog;
}

class CZEpgControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZEpgControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZEpgControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZEpgControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZEpgControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZEpgControlDialog(QWidget *parent);
    ~ZEpgControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZEpgControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZEpgControlWidgetItem;

private Q_SLOTS:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZEPGCONTROLDIALOG_H
