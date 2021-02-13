TEMPLATE = subdirs

SUBDIRS += \
    main \
    view \
    util

main.depends=view
view.depends=util