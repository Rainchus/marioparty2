import subprocess

def parse_and_format(input_file_path, output_file_path):
    with open(input_file_path, 'r') as file:
        lines = file.readlines()

    formatted_lines = []

    for line in lines:
        if line.strip() == '//data and bss':
            break
        parts = line.split(' = ')
        if len(parts) != 2:
            continue
        
        name = parts[0].strip()
        address = parts[1].split(';')[0].strip()
        address = address.replace('0x', '')  # Strip the '0x' prefix
        formatted_line = f"{address},code,{name}"
        formatted_lines.append(formatted_line)
    
    with open(output_file_path, 'w') as file:
        file.write('\n'.join(formatted_lines))

def move_file(source, destination):
    try:
        # Using the shell mode to handle paths with spaces and special characters
        subprocess.run(f'cp "{source}" "{destination}"', shell=True, check=True)
        subprocess.run(f'rm "{source}"', shell=True, check=True)  # Remove the original file after copying
        print(f"File moved to {destination}")
    except subprocess.CalledProcessError as e:
        print(f"Error occurred: {e}")

# Specify the paths to your input and output files
input_file_path = 'symbol_addrs.txt'
output_file_path = 'MarioParty2.sym'
final_destination = ''

parse_and_format(input_file_path, output_file_path)
move_file(output_file_path, final_destination)
