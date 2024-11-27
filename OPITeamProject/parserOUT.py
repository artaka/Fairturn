import os
import pickle
import csv
from googleapiclient.discovery import build

# Функция для записи данных из файла в Google Sheets
def upload_csv_to_gsheet(csv_file_path, spreadsheet_id, worksheet_name, credentials_path):
    """Загрузка данных из CSV в Google Sheets."""
    try:
        # Проверяем наличие файла токена
        if not os.path.exists(credentials_path):
            raise FileNotFoundError(f"Файл токена {credentials_path} не найден. Выполните авторизацию.")
        
        # Авторизация с помощью токена
        with open(credentials_path, 'rb') as token:
            credentials = pickle.load(token)

        # Создание API-клиента
        service = build('sheets', 'v4', credentials=credentials)

        # Чтение данных из CSV-файла
        if not os.path.exists(csv_file_path):
            raise FileNotFoundError(f"CSV файл {csv_file_path} не найден.")
        
        with open(csv_file_path, 'r', encoding='utf-8') as csvfile:
            reader = csv.reader(csvfile)
            values = list(reader)

        # Запись данных в таблицу Google Sheets
        body = {
            'values': values
        }
        range_name = worksheet_name
        result = service.spreadsheets().values().update(
            spreadsheetId=spreadsheet_id,
            range=range_name,
            valueInputOption="RAW",
            body=body
        ).execute()

        print(f"Данные из файла {csv_file_path} успешно загружены в таблицу Google Sheets.")
    except Exception as e:
        print(f"Ошибка при загрузке данных: {e}")

if __name__ == "__main__":
    # Ввод данных через консоль
    print("Введите данные для загрузки в Google Sheets:")
    
    # Путь к CSV-файлу с обработкой умолчаний
    csv_file_path = input("Путь к CSV-файлу (по умолчанию 'output.csv', введите 'd' для умолчания): ").strip()
    if csv_file_path.lower() == 'd' or not csv_file_path:
        csv_file_path = 'output.csv'

    # ID таблицы
    spreadsheet_id = input("ID таблицы: ").strip()
    worksheet_name = input("Название листа (например, 'Sheet1'): ").strip()

    # Путь к файлу токена с обработкой умолчаний
    credentials_path = input("Путь к файлу токена (по умолчанию 'token.pickle', введите 'd' для умолчания): ").strip()
    if credentials_path.lower() == 'd' or not credentials_path:
        credentials_path = 'token.pickle'

    # Вызов функции
    upload_csv_to_gsheet(csv_file_path, spreadsheet_id, worksheet_name, credentials_path)
