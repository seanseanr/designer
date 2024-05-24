TEMPLATE    = subdirs
SUBDIRS     = calculatorform \
    QLampPlugin

!static:SUBDIRS += calculatorbuilder \
                   containerextension \
                   customwidgetplugin \
                   taskmenuextension \
                   worldtimeclockbuilder \
                   worldtimeclockplugin

# the sun cc compiler has a problem with the include lines for the form.prf
solaris-cc*:SUBDIRS -= calculatorbuilder \
		       worldtimeclockbuilder
		     

# install
QT_INSTALL_EXAMPLES = D:/Qt/work/designer/
QT_BUILD_TREE = D:/4.8.7-X86-64/
QT_INSTALL_PLUGINS= D:/4.8.7-X86-64/plugins
sources.files = *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer
INSTALLS += sources

