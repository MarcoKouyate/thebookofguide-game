
set(APP_LIBRARY GuidesChapterCore)
set(CROSSPATFORM_SRC_FILES)

list(APPEND CROSSPATFORM_SRC_FILES
     GameScene.cpp
     )


add_library(${APP_LIBRARY} ${CROSSPATFORM_SRC_FILES})
