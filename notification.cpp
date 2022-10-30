#include "notification.h"
#include <QSystemTrayIcon>
notification::notification()
{

}
void notification::ajout_notification()
{

      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

      notifyIcon->setIcon(QIcon("C:\\iintegration\\SBS\\img\\icon.jpg"));
      notifyIcon->show();

      notifyIcon->showMessage("Declaration Ajoutee ","Une nouvelle declaration  a été ajoutée",QSystemTrayIcon::Information,15000);

}
void notification::notification_supprimer()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("C:\\iintegration\\SBS\\img\\icon.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Declaration supprimee","Une Declaration a été  supprimée ",QSystemTrayIcon::Critical,15000);
}
void notification::notification_modifier()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:\\iintegration\\SBS\\img\\icon.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Declaration modifiee","Une Declaration  a éte modifié ",QSystemTrayIcon::Warning,15000);
}
