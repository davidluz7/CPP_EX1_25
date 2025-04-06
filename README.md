# CPP_EX1_25

# Graph Project - מטלה 1

## תיאור כללי
הפרויקט מממש גרף באמצעות רשימת שכנויות (Adjacency List) ומכיל מימוש של אלגוריתמים קלאסיים:
- BFS
- DFS
- Dijkstra
- Prim
- Kruskal

כל המחלקות ממומשות **ללא שימוש ב־STL**, תוך ניהול זיכרון ידני, לפי דרישות הקורס.

## 📁 מבנה הקבצים
| קובץ | תיאור |

| `graph.hpp/cpp` | מחלקת הגרף, כולל פעולות בסיסיות (addEdge, removeEdge, print_graph) |
| `algorithms.hpp/cpp` | מימוש אלגוריתמים על הגרף |
| `queue.hpp/cpp` | מימוש תור בסיסי |
| `priority_queue.hpp/cpp` | מימוש תור עדיפויות פשוט |
| `union_find.hpp/cpp` | מבנה Union-Find עם path compression ו-union by rank |
| `main.cpp` | קובץ הדגמה של שימוש בגרף ובאלגוריתמים |
| `tests.cpp` | בדיקות יחידה באמצעות הספרייה `doctest` |
| `Makefile` | בניית הפרויקט, הרצת בדיקות ובדיקת זליגות זיכרון |
| `doctest.h` | ספריית בדיקות חיצונית שהוספה לפרויקט |


## פקודות Makefile
| פקודה | פעולה |
| `make Main` | קומפילציה והרצה של קובץ `main.cpp` |
| `make test` | הרצת בדיקות יחידה מ-`tests.cpp` |
| `make valgrind` | בדיקת זליגות זיכרון באמצעות Valgrind |
| `make clean` | ניקוי קבצי הרצה (`Main`, `test`) |
