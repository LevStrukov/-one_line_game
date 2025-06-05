#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iostream>  

#include "graphics.h"
#include "game.h"

using namespace std;

const int RADIUS = 16;

vector<Point> points;
vector<pair<int, int>> edges;
vector<pair<int, int>> visitedEdges;
int lastSelected = -1;

bool isConnected(int a, int b) {
    for (auto &edge : edges) {
        if ((edge.first == a && edge.second == b) ||
            (edge.first == b && edge.second == a))
            return true;
    }
    return false;
}

bool isVisited(int a, int b) {
    for (auto &edge : visitedEdges) {
        if ((edge.first == a && edge.second == b) ||
            (edge.first == b && edge.second == a))
            return true;
    }
    return false;
}

int getPointIndex(int mx, int my) {
    for (int i = 0; i < points.size(); ++i) {
        int dx = mx - points[i].x;
        int dy = my - points[i].y;
        if (dx * dx + dy * dy <= RADIUS * RADIUS)
            return i;
    }
    return -1;
}

void drawPoints() {
    for (int i = 0; i < points.size(); ++i) {
        Point p = points[i];

        setcolor(BLACK);
        setfillstyle(SOLID_FILL, COLOR(144, 238, 144));  
        fillellipse(p.x, p.y, RADIUS, RADIUS);

        if (i == lastSelected) {
            setcolor(RED);
            setlinestyle(SOLID_LINE, 0, 3);
            circle(p.x, p.y, RADIUS + 4);
            setlinestyle(SOLID_LINE, 0, 1);
        }
    }
}

void drawEdges() {
    setlinestyle(SOLID_LINE, 0, 3);
    setcolor(LIGHTGRAY);
    for (auto &e : edges) {
        line(points[e.first].x, points[e.first].y,
             points[e.second].x, points[e.second].y);
    }
    setlinestyle(SOLID_LINE, 0, 1);
}

void drawVisitedEdges() {
    setlinestyle(SOLID_LINE, 0, 3);
    setcolor(LIGHTGRAY);  
    for (auto &e : visitedEdges) {
        line(points[e.first].x, points[e.first].y,
             points[e.second].x, points[e.second].y);
    }

    setcolor(BLACK);  
    setlinestyle(SOLID_LINE, 0, 1);
    for (auto &e : visitedEdges) {
        line(points[e.first].x, points[e.first].y,
             points[e.second].x, points[e.second].y);
    }
}

bool allVisited() {
    return visitedEdges.size() == edges.size();
}

bool loadLevel(const char *filename) {
    std::ifstream file(filename);

    int numPoints = 0;
    file >> numPoints;

    points.clear();
    for (int i = 0; i < numPoints; ++i) {
        int x, y;
        file >> x >> y;
        points.push_back({x, y});
    }

    int numEdges = 0;
    file >> numEdges;

    edges.clear();
    for (int i = 0; i < numEdges; ++i) {
        int a, b;
        file >> a >> b;
        edges.emplace_back(a, b);
    }

    return true;
}

void game() 
{
   srand(time(0));

   int levelNumber = 1 + rand() % 3;
   string levelFilename = "levels/00" + to_string(levelNumber) + ".txt";

   while (true)
   {
      if (!loadLevel(levelFilename.c_str())) 
      {
         cerr << "Не удалось загрузить уровень: " << levelFilename << endl;
      }

      lastSelected = -1;
      visitedEdges.clear();

      bool restart = false;

      while (!allVisited())
      {
         setbkcolor(WHITE);
         cleardevice();

         drawEdges();
         drawVisitedEdges();
         drawPoints();

            if (ismouseclick(WM_LBUTTONDOWN)) {
                int mx, my;
                getmouseclick(WM_LBUTTONDOWN, mx, my);
                int index = getPointIndex(mx, my);

                if (index != -1) {
                    if (lastSelected == -1) {
                        lastSelected = index;
                    } else if (isConnected(lastSelected, index) && !isVisited(lastSelected, index)) {
                        visitedEdges.push_back({lastSelected, index});
                        lastSelected = index;
                    }
                }
            }

         if (kbhit())
         {
            int key = getch();
            if (key == KEY_ENTER) 
            { 
               restart = true;
               break;
            }
            else if (key == KEY_ESC) 
            { 
               return;
            }
         }

         swapbuffers();
         delay(10);
      }

        if (!restart) {
         cleardevice();
         drawEdges();
         drawVisitedEdges();
         drawPoints();
         settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
         outtextxy(300, 540, "Вы победили!");
         swapbuffers();

         getch(); 
         break;
      }
   }
}
