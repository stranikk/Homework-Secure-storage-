# Secure storage

##Описание 

Secure storage - приложение разработана в качестве дз по дисцеплине алгоритмические языки 
студентом 2 -го курса группы ИУ8-34 МГТУ им. Баумана Курганов Н.С 

##Сборка проекта

* Клонируем репозиторий
* Скачиваем Qt Creator версии 5.6.2
* Устанавливаем криптографическию библиотеку botan и подключаем библиотеку, соответствующую системе
* В проекте в database.cpp в методе прописываем путь к базе данных (база хранится в папке проекта в папке Data
```
void DataBase::connectDatabase()
{
    //Подключаем базу данных
   QSqlDatabase db;
   db = QSqlDatabase::addDatabase("QSQLITE");


   db.setDatabaseName("Путь до базы данных");


   if(!db.open()){
         qDebug() << "Не удалось восстановить базу данных";
   }
}
```
* Собираем проект
