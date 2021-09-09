QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        humandetector.cpp \
        main.cpp

INCLUDEPATH += /usr/local/include/opencv4\

LIBS += -L/usr/local/lib \
     -lopencv_gapi \
     -lopencv_stitching \
     -lopencv_alphamat \
     -lopencv_aruco \
     -lopencv_barcode \
     -lopencv_bgsegm \
     -lopencv_bioinspired \
     -lopencv_ccalib \
     -lopencv_dnn_objdetect \
     -lopencv_dnn_superres \
     -lopencv_dpm \
     -lopencv_face \
     -lopencv_freetype \
     -lopencv_fuzzy \
     -lopencv_hfs \
     -lopencv_img_hash \
     -lopencv_intensity_transform \
     -lopencv_line_descriptor \
     -lopencv_mcc \
     -lopencv_quality \
     -lopencv_rapid \
     -lopencv_reg \
     -lopencv_rgbd \
     -lopencv_saliency \
     -lopencv_sfm \
     -lopencv_stereo \
     -lopencv_structured_light \
     -lopencv_phase_unwrapping \
     -lopencv_superres \
     -lopencv_optflow \
     -lopencv_surface_matching \
     -lopencv_tracking \
     -lopencv_highgui \
     -lopencv_datasets \
     -lopencv_text \
     -lopencv_plot \
     -lopencv_videostab \
     -lopencv_videoio \
     -lopencv_viz \
     -lopencv_wechat_qrcode \
     -lopencv_xfeatures2d \
     -lopencv_shape \
     -lopencv_ml \
     -lopencv_ximgproc \
     -lopencv_video \
     -lopencv_dnn \
     -lopencv_xobjdetect \
     -lopencv_objdetect \
     -lopencv_calib3d \
     -lopencv_imgcodecs \
     -lopencv_features2d \
     -lopencv_flann \
     -lopencv_xphoto \
     -lopencv_photo \
     -lopencv_imgproc \
     -lopencv_core


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    humandetector.h

DISTFILES += \
    svmClassifier
