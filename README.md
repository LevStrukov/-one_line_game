# 🔗 Игра «Одной линией» на C++

Головоломка на внимательность и стратегию: соедините все заданные рёбра графа, щёлкая по точкам в нужном порядке. Игра реализована на языке C++ с графическим интерфейсом с помощью библиотеки **WinBGIm**.

---

## 🎮 Цель игры

Соединить все рёбра графа, не повторяя уже пройденные связи. Пользователь кликает по точкам (вершинам графа), и если между двумя последними выбранами точками есть рёбра — они соединяются. После прохождения всех рёбер — игрок побеждает.

---

## 🛠 Используемые технологии

- **Язык программирования**: C++
- **Графика**: WinBGIm (`graphics.h`)
- **Файлы уровня**: текстовые `.txt` с координатами точек и списком рёбер
- **IDE**: MinIDE / Dev-C++ / любой компилятор с поддержкой WinBGIm

---

## 📂 Структура проекта

├── game.cpp # Основная логика игры
├── game.h # Заголовочный файл (структуры и прототипы)
├── levels/
│ ├── 001.txt # Уровень 1
│ ├── 002.txt # Уровень 2
│ └── 003.txt # Уровень 3
├── README.md # Описание проекта


---

## 📄 Формат файла уровня

Каждый уровень представляет собой текстовый файл в формате:

N # количество точек
x1 y1
x2 y2
...
xN yN

M # количество рёбер
a1 b1
a2 b2
...
aM bM


- `xi yi` — координаты точки (в пикселях)
- `ai bi` — индексы вершин, между которыми есть ребро (индексация с 0)

---

## 🕹 Управление

| Действие        | Клавиша/действие             |
|-----------------|------------------------------|
| Выбрать точку   | ЛКМ по точке                 |
| Перезапуск      | `ENTER`                      |
| Выход из игры   | `ESC`                        |

---

## 📌 Особенности

- Рандомный выбор одного из 3-х уровней при запуске
- Подсветка выбранной точки
- Поддержка "уже соединённых" рёбер (не дублируются)
- Победное сообщение при успешном прохождении
- Поддержка перезапуска уровня и выхода из игры

---

## ▶️ Как запустить

1. Установите WinBGIm и настройте вашу среду разработки.
2. Убедитесь, что папка `levels/` содержит уровни (`001.txt`, `002.txt`, `003.txt`).
3. Скомпилируйте `game.cpp` вместе с `graphics.h` и `game.h`.
4. Запустите исполняемый файл — один из уровней будет выбран случайным образом.

---

## 🏁 Победа

После соединения всех рёбер отображается сообщение **«Вы победили!»**. Для выхода — нажмите любую клавишу.

---

## 👤 Автор

**Струков Л.О.**  
Южно-Уральский государственный университет  
Кафедра прикладной математики и программирования

---

## 📝 Лицензия

Проект создан в учебных целях и распространяется свободно для образовательного использования.

