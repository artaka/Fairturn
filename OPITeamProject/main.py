import pickle
import csv
from googleapiclient.discovery import build

# Укажите данные вашей таблицы Google Sheets
SPREADSHEET_ID = '1HhpLGsL7zcT4HoXK1HGV9lPfyUTMgChiCYtTPKTa9CQ'  # ID таблицы
WORKSHEET_NAME = 'testing'  # Название листа (вкладки) в таблице
CSV_FILE_PATH = 'output.csv'  # Имя файла для сохранения данных
CREDENTIALS_PATH = 'token.pickle'  # Путь к файлу токена

# Функция для чтения данных из листа Google Sheets
def download_gsheet_to_csv(spreadsheet_id, worksheet_name, csv_file_path):
    # Авторизация с помощью токена
    with open(CREDENTIALS_PATH, 'rb') as token:
        credentials = pickle.load(token)
    
    # Создание API-клиента
    service = build('sheets', 'v4', credentials=credentials)

    # Чтение данных из таблицы
    range_name = f"{worksheet_name}"  # Считаем весь лист
    result = service.spreadsheets().values().get(spreadsheetId=spreadsheet_id, range=range_name).execute()
    values = result.get('values', [])  # Получаем данные ячеек

    # Запись данных в CSV
    with open(csv_file_path, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerows(values)

    print(f"Данные сохранены в файл {csv_file_path}")

# Вызов функции для скачивания листа
download_gsheet_to_csv(SPREADSHEET_ID, WORKSHEET_NAME, CSV_FILE_PATH)
