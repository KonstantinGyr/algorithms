# ДЗ 

### 1. Pentium 4
★★☆☆☆

Требуется реализовать методы в `TextEditor.cpp`

Спустившись в подвал вашего дома, вы обнаружили там компьютер родом из 90х годов двадцатого века. Он обладал странным вздувшимся монитором, а пожелтевший пластик корпуса был покрыт толстым слоем пыли. Расчистив залежи перфокарт и окаменелостей, вы нашли на компьютере рубильник включения, и с удивлением обнаружили что этот динозавр даже включается. 

Ламповый процессор зашуршал шестеренками и на экране появилась заставка доисторической операционной системы. 
Порывшись в файлах на этом компьютере вы обнаружили что кто-то из ваших далеких предков пытался написать на этой ЭВМ программу-текстовый редактор. Неизвестный автор оставил в исходных кодах несколько комментариев и следующее описание функций:


```cpp
class TextEditor {
// Больше 255 символов в память не влезает =/
public:
    char text[255]; // Тип String ещё не изобрели :(
    int textLength; // текущая длина текста в массиве text

    // Пустое место в этом массиве забито просто “пробелами”
    // Например если textLength = 3, и text = {‘ш’,’к’,’я’, … еще 252 символа ‘пробел’ .. }

    void insertCharacterAt(int position, char c) {
        // Эта функция должна вставлять символ в строку на позиции position
        // Например когда пользователь напечатал “При|ет мир!” (этот текст у нас в переменной text)
        // и его курсор находится между буквами “и” и “е”, и он нажимает “в”.
        // В этот момент вызывается функция insertCharacterAt(3, “в”), после чего в переменной text значение меняется на “Привет мир!”
    }

    void backspace(int position) {
    /   / "Привет Мм|ир!" => "Привет Мир!"
    }

    void print() {
        for (int i = 0; i < textLength; ++i) {
            cout << text[i];
        }
        cout << endl;
    }

    // Конструктор готов!
    TextEditor() {
        textLength = 0;
        for (int i = 0; i < 255; i++) {
            text[i] = ' ';
        }
    }
};
```
Прочтя все это вы понимаете что это ваше предназначение и священный долг — закончить эту работу и реализовать эти две функции.


### 2. Спасите детей
★★☆☆☆

Требуется реализовать методы в `SaveChildren.cpp`
К вам обратилась младшая группа детского сада, которой требовалась помощь в выполнении упражнений.
Воспитатели все время заставляли детей собирать слова из кубиков в качестве развивающего упражнения, и требовали переделывать результат если у разных детей получались одинаковые слова.
```cpp
vector<vector<char>> words =  {
    {'ш', 'б', 'а', 'к', 'а' },
    {'к', 'а', 'т', 'e', 'н', 'к' },
    {'г', 'у', 'с', 'ъ', 'к' },
    {'ш', 'б', 'а', 'к', 'а' },
}
```

Как видите у первого и последнего ребенка получились одинаковые слова. Дети придумали следующий алгоритм чтобы исправить ситуацию: один из детей с совпавшими словами просто переставлял первый кубик с буквой в конец.

```сpp
vector<vector<char>> words = {
    { 'б', 'а', 'к', 'а', 'ш'}, // бакаш, вместо шбака
    {'к', 'а', 'т', 'e', 'н', 'к' },
    {'г', 'у', 'с', 'ъ', 'к' },
    {'ш', 'б', 'а', 'к', 'а' },
}
```
Этот алгоритм работал, пока в группу не набрали еще детей, и кто-то из них сразу составил слово “Бакаш”. Получается что после первого исправления “Шбака” на “Бакаш”, в списке все равно оставались повторяющиеся слова.

Используйте алгоритм придуманный детьми (переставлять первый кубик с буквой в конец слова), до тех пор пока список слов не будет состоять только из уникальных слов.
```cpp
void permutateWords(vector<vector<char>> words) {
}
```


### 3. Молодые таланты
★★★★☆

Требуется реализовать методы в `RandomSort.cpp`


Студент первого курса факультета информатики придумал новый гениальный алгоритм сортировки массива.
“Ну это, там, же,  если проста взять евойный массив да перитряхивать его, тудык-сюдык, пока оно там само ни образумется”. Нам так понравилась эта идея, что мы решили включить эту задачу в наш курс.

Реализуйте функцию, которая проверяет, отсортирован ли массив.

```cpp
bool myIsSorted(const vector<int>& array) {
    
}
```

Используйте ее, чтобы реализовать функцию сортировки
```cpp
void RandomSort(vector<int>& array) {}
```

Которая должна выбирать два случайных элемента массива и менять их местами, проверяя стал ли массив отсортирован или нет, продолжая делать это до тех пор, пока массив не станет отсортированным.
Такая операция может занять много времени, поэтому тестировать все это мы будем на небольших массивах из 5-10 элементов.

**(опционально)** В поисках острых ощущений вы можете проверить насколько большой массив ваш компьютер сможет отсортировать этим методом за одну минуту.  
