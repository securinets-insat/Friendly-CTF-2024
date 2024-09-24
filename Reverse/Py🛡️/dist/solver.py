import subprocess
from collections import defaultdict

def run_script():
    result = subprocess.run(['python', 'script.py'], capture_output=True, text=True)
    return result.stdout.strip()

def collect_chunks(num_runs=100):
    chunks = []
    for _ in range(num_runs):
        chunk = run_script()
        if chunk:
            chunks.append(chunk)
    return chunks

def deduce_string(chunks, known_start='Securinets', known_end='}'):
    chunk_map = defaultdict(list)

    for chunk in chunks:
        for other_chunk in chunks:
            if chunk != other_chunk:
                if chunk[1:] == other_chunk[:2]:  
                    chunk_map[chunk].append(other_chunk)

    result = known_start
    current_chunk = known_start[-3:]

    while current_chunk != known_end and current_chunk in chunk_map:
        next_chunks = chunk_map[current_chunk]
        found_next = False

        for next_chunk in next_chunks:
            if next_chunk not in result:
                result += next_chunk[2:]
                current_chunk = next_chunk
                found_next = True
                break

        if not found_next:
            break

    if result[-1] != known_end:
        result += known_end

    return result

if __name__ == "__main__":
    chunks = collect_chunks(200)
    print("Collected chunks:", chunks)
    
    original_string = deduce_string(chunks, known_start='Securinets', known_end='}')
    print("Reconstructed string:", original_string)
