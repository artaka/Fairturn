import os
import pickle
import csv
from googleapiclient.discovery import build

# Функция для чтения данных из листа Google Sheets
def download_gsheet_to_csv(spreadsheet_id, worksheet_name, csv_file_path, credentials_path):
    """Загрузка данных из Google Sheets в CSV."""
    try:
        # Проверяем наличие файла токена
        if not os.path.exists(credentials_path):
            raise FileNotFoundError(f"Файл токена {credentials_path} не найден. Выполните авторизацию.")
        
        # Авторизация с помощью токена
        with open(credentials_path, 'rb') as token:
            credentials = pickle.load(token)

        # Создание API-клиента
        service = build('sheets', 'v4', credentials=credentials)

        # Чтение данных из таблицы
        range_name = worksheet_name
        result = service.spreadsheets().values().get(spreadsheetId=spreadsheet_id, range=range_name).execute()
        values = result.get('values', [])

        # Проверка наличия данных
        if not values:
            print("Лист пуст или данные не найдены.")
            return

        # Запись данных в CSV
        with open(csv_file_path, 'w', newline='', encoding='utf-8') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerows(values)

        print(f"Данные успешно сохранены в файл {csv_file_path}")
    except Exception as e:
        print(f"Ошибка при загрузке данных: {e}")

if __name__ == "__main__":
    # Ввод данных через консоль
    print("Введите данные для загрузки Google Sheets:")
    spreadsheet_id = input("ID таблицы: ").strip()
    worksheet_name = input("Название листа: ").strip()

    # Ввод с обработкой умолчаний
    csv_file_path = input("Путь для сохранения CSV (по умолчанию 'output.csv', введите 'd' для умолчания): ").strip()
    if csv_file_path.lower() == 'd' or not csv_file_path:
        csv_file_path = 'output.csv'

    credentials_path = input("Путь к файлу токена (по умолчанию 'token.pickle', введите 'd' для умолчания): ").strip()
    if credentials_path.lower() == 'd' or not credentials_path:
        credentials_path = 'token.pickle'

    # Вызов функции
    download_gsheet_to_csv(spreadsheet_id, worksheet_name, csv_file_path, credentials_path)
