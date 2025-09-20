import pickle
from google_auth_oauthlib.flow import InstalledAppFlow

# Настройки доступа к Google Sheets API
SCOPES = ['https://www.googleapis.com/auth/spreadsheets']

def get_google_token():
    # Создаем поток аутентификации
    flow = InstalledAppFlow.from_client_secrets_file(
        'credentials.json',
        SCOPES
    )
    
    # Запускаем локальный сервер для авторизации
    creds = flow.run_local_server(port=8080)
    
    # Сохраняем полученные учетные данные в файл
    with open('token.pickle', 'wb') as token:
        pickle.dump(creds, token)
    
    print("Токен успешно сохранен в token.pickle")

if __name__ == '__main__':
    get_google_token()