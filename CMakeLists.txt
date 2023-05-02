cmake_minimum_required(VERSION 3.23)
project(multiText)

set(CMAKE_CXX_STANDARD 17)

add_executable(multiText main.cpp Typing.cpp Typing.h Application.cpp Application.h MultiText.cpp MultiText.h Letter.cpp Letter.h States.cpp States.h Snapshot.cpp Snapshot.h GUIComponent.cpp GUIComponent.h EventHandler.h KeyShortcuts.cpp KeyShortcuts.h TextInput.cpp TextInput.h MultiTextSnapshot.cpp MultiTextSnapshot.h History.cpp History.h HistoryNode.h SnapshotInterface.cpp SnapshotInterface.h Textbox.cpp Textbox.h MouseEvents.cpp MouseEvents.h TextInputSnapshot.cpp TextInputSnapshot.h Cursor.cpp Cursor.h Position.cpp Position.h Label.cpp Label.h ColorChanger.cpp ColorChanger.h Word.cpp Word.h FileReader.cpp FileReader.h WordSort.cpp WordSort.h Heap.cpp Heap.h NewColorChanger.cpp NewColorChanger.h
        FileTreeNode.h FileTree.cpp FileTree.h FileItem.cpp FileItem.h Font.cpp Font.h SFMLFileTreeNode.cpp SFMLFileTreeNode.h SFMLFileTree.cpp SFMLFileTree.h Clothing.cpp Clothing.h Circle.cpp Circle.h SaveCircle.h SaveCircle.cpp
        Item.cpp Item.h DropDownMenu.cpp DropDownMenu.h ItemList.cpp ItemList.h InputBox.cpp InputBox.h DropDownSnapshot.cpp DropDownSnapshot.h Menu.cpp Menu.h Character.cpp Character.h Images.cpp Images.h ScreenComponents.cpp ScreenComponents.h CustomCursor.cpp CustomCursor.h AppGame.cpp AppGame.h OptionsBar.cpp OptionsBar.h Panel.cpp Panel.h Closet.cpp Closet.h Settings.cpp Settings.h)

target_link_libraries(multiText sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)