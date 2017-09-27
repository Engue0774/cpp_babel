#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include "UIManager.hpp"

namespace Ui {
class MainWindow;
}

namespace babel {
    class UIManager;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent, babel::UIManager &uiManager);
    ~MainWindow();

    QListWidget         *getFriendsList();
    QLabel              *getGeneralInformations();

public slots:
    void FilterFriendsList(QString const& filterText);
    void RedirectToLoginDiag();
    void SelectedFriendClicked(QListWidgetItem *selectedContact);
    void OpenAddContactWindow();

private:
    Ui::MainWindow      *_ui;
    babel::UIManager    &_uiManager;
};

#endif // MAINWINDOW_H
