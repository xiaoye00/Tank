TEMPLATE = subdirs

SUBDIRS += \
    main \
    util \
    db

main.depends=util
main.depends=db
db.depends=util