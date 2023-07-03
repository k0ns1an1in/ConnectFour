cmake_minimum_required(VERSION 3.24)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 23)

add_executable(ConnectFour main.cpp GUI.h GUI.cpp Verwaltung.h Verwaltung.cpp Spielertypen/Spieler.hpp Spielertypen/Spieler.cpp Spielertypen/VertikalerBot.cpp Spielertypen/Bots.cpp Spielertypen/Mensch.cpp Spielertypen/SchlauerBot.cpp Spielertypen/test.cpp Spielertypen/ZufallsBot.cpp Spielertypen/HorizontalerBot.cpp ConsoleColor.h)
