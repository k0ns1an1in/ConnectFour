cmake_minimum_required(VERSION 3.24)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 23)

add_executable(ConnectFour main.cpp Graphics/GUI.h Graphics/GUI.cpp Verwaltung/Verwaltung.h Verwaltung/Verwaltung.cpp Spielertypen/Spieler.hpp Spielertypen/Spieler.cpp Spielertypen/VertikalerBot.cpp Spielertypen/Bots.cpp Spielertypen/Mensch.cpp Spielertypen/SchlauerBot.cpp Spielertypen/test.cpp Spielertypen/ZufallsBot.cpp Spielertypen/HorizontalerBot.cpp Graphics/ConsoleColor.h)
