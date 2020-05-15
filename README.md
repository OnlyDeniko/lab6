# Лабораторная работа №6

Реализация структуры данных плекс для хранения и редактирования геометрических объектов
---------------------------------------------------------------------------------------

Реализация может строить плекс по заданной конфигурации из точек и линий (два простейших геометрических объекта). 

При нажатии кнопки "Добавить плекс" строится плекс и два файла (outputGraph.txt и outputFile.txt), содержащие граф и запись обхода графа (левая вершина, правая вершина, текущая), описывающие данный плекс, соттветственно.

Для того, чтобы отредактировать outputGraph.txt в нужном виде необходимо отредактировать функцию saveGraph() в классе Plex изменением второго начального параметра(width) dfsForSaveGraph(...) и двух параметров внутри функции dfs, которые отвечают за отступы при построении графа(строки  250 и 255).

В реализации нет: загрузки из файла, изменения цвета плекса.

Реализации обходов плекса реализованы с помощью рекурсивного обхода в глубину.