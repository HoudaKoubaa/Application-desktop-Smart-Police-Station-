#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql network multimedia charts serialport

QT       += core gui printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += core gui sql multimedia multimediawidgets charts


QT += widgets
QT +=charts
QT += printsupport
CONFIG += resources_big
CONFIG += c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acceuil.cpp \
    accident.cpp \
    arduino.cpp \
    assistance.cpp \
    barchart.cpp \
    citoyen.cpp \
    conge.cpp \
    connection.cpp \
    dialogemploye.cpp \
    employes.cpp \
    login.cpp \
    mailing.cpp \
    main.cpp \
    maintenance.cpp \
    mainwindow.cpp \
    notification.cpp \
    nvcompte.cpp \
    piechart.cpp \
    quitter.cpp \
    rdv.cpp \
    sign.cpp \
    sms.cpp \
    smtp.cpp \
    vehicule.cpp \
    violence.cpp

HEADERS += \
    acceuil.h \
    accident.h \
    arduino.h \
    assistance.h \
    citoyen.h \
    conge.h \
    connection.h \
    dialogemploye.h \
    employes.h \
    login.h \
    mailing.h \
    maintenance.h \
    mainwindow.h \
    notification.h \
    nvcompte.h \
    quitter.h \
    rdv.h \
    sign.h \
    sms.h \
    smtp.h \
    vehicule.h \
    violence.h

FORMS += \
    acceuil.ui \
    dialogemploye.ui \
    mailing.ui \
    mainwindow.ui \
    quitter.ui \
    sign.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    img/151063767_429005728336484_2086052602840462546_n.png \
    img/182484728_1001694200366980_6117544729765152706_n.png \
    img/182486389_729248067754259_6659584539846534587_n.png \
    img/182621297_495351015044474_391931727743189441_n.png \
    img/182895477_888405928672833_3764222974050923583_n.png \
    img/183097748_793064294947771_710383781197153546_n.png \
    img/183414194_466884714594269_7112138142974174459_n.png \
    img/52328332_2078164858899734_1395457921264910336_n.png \
    img/71877099_1515757621897753_1533596121182502912_n.png \
    img/79646791_2555477274559182_3424678394934067200_n.png \
    img/82385804_2643811335712023_8677046488792039424_n.png \
    img/Capture.JPG \
    img/acceuil.JPG \
    img/add-button.png \
    img/african-american-policeman-writing-report-wearing-uniform-cop-guard-JKJG2T.jpg \
    img/ascending-sort.png \
    img/authentification.png \
    img/back.jpg \
    img/back2.jpg \
    img/background.jpg \
    img/button.png \
    img/car-accident.png \
    img/conversation.png \
    img/delete.png \
    img/edit.png \
    img/empty.png \
    img/eye.png \
    img/handcuffs (1).png \
    img/handcuffs (1).png \
    img/home.png \
    img/icon.jpg \
    img/icons8-clock.gif \
    img/icons8-close-window-48.png \
    img/icons8-delete-48.png \
    img/icons8-doughnut-chart-100.png \
    img/icons8-edit-48.png \
    img/icons8-edit.gif \
    img/icons8-email-send-240.png \
    img/icons8-futures-100.png \
    img/icons8-go-back-48.png \
    img/icons8-home-240.png \
    img/icons8-home-48.png \
    img/icons8-info-48.png \
    img/icons8-lock.gif \
    img/icons8-mailbox-240.png \
    img/icons8-mailbox-48.png \
    img/icons8-mailbox.gif \
    img/icons8-menu.gif \
    img/icons8-music.gif \
    img/icons8-pie-chart-100.png \
    img/icons8-police-badge-100.png \
    img/icons8-remove-48.png \
    img/icons8-search.gif \
    img/icons8-send-to-printer-240.png \
    img/icons8-services.gif \
    img/icons8-statistics-100.png \
    img/icons8-trash-can-48.png \
    img/icons8-trash.gif \
    img/images.png \
    img/instagram-stories.png \
    img/lock.png \
    img/logo (2).png \
    img/logo (2).png \
    img/logo (2).png \
    img/logo (2).png \
    img/logo (2).png \
    img/logo (2).png \
    img/logo (2).png \
    img/logo (2).png \
    img/logo (2).png \
    img/logo(1).png \
    img/logo.png \
    img/logout (1).png \
    img/logout (1).png \
    img/logout (1).png \
    img/logout (1).png \
    img/logout (1).png \
    img/mail.png \
    img/mailbox(1).png \
    img/mailbox.png \
    img/monote.jpg \
    img/music-player-1446499-1222214(1).png \
    img/music-player-1446499-1222214.png \
    img/note(1).png \
    img/note.png \
    img/oval.png \
    img/overpopulation.png \
    img/password(1).png \
    img/password.png \
    img/pdclogin.png \
    img/physical-abuse(1).png \
    img/physical-abuse.png \
    img/pie-chart.png \
    img/play.png \
    img/player-navigation-icons-play-stop-and-pause-vector-.png \
    img/player-navigation-icons-play-stop-and-pause-vector-5509880.png \
    img/pngtree-vector-high-volume-icon-png-image_313059.jpg \
    img/pngtree-vector-high-volume-icon-png-image_313059.png \
    img/police (1).png \
    img/police (1).png \
    img/police-station (2).png \
    img/police-station (2).png \
    img/police-station.png \
    img/police.png \
    img/policeman-background_48369-15139.jpg \
    img/policeman-hold-shield-wearing-helmet-uniform-cop-guard-brick-background_48369-15139.jpg \
    img/policeman-writing-report-wearing-uniform-cop-guard-brick-background_48369-15138.jpg \
    img/policier-travaillant-ordinateur-portant-flic-uniforme-dans-bureau-garde-fond-brique_48369-15140.jpg \
    img/printer.png \
    img/prisonBreak.mp3 \
    img/satat.png \
    img/share.png \
    img/sms.png \
    img/social.png \
    img/son.wav \
    img/sss.png \
    img/stop.png \
    img/test.jpg \
    img/text-message.png \
    img/trash.jpg \
    img/trashh.jpg \
    img/user.png \
    img/viewer.png
