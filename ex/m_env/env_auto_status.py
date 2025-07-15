# env_auto_status.py

NOTEFILE = "env_status.txt"
NORMLOG = "norm.log"

FILES = [
    "add_env.c", "del_env.c", "fre_chr_env.c", "fre_env.c", "gky_env.c",
    "grp_env.c", "int_chr_env.c", "int_env.c", "lvl_env.c", "prn_env.c", "prn_port_env.c"
]

def has_norminette_ok(filename, log):
    import subprocess
    try:
        result = subprocess.run(
            ["norminette", filename],
            capture_output=True,
            text=True
        )
        log.write(f"\n{filename}\n")
        log.write(result.stdout)
        return "OK!" in result.stdout
    except Exception as e:
        log.write(f"\n{filename}\nError: {e}\n")
        return False

def update_note_file():
    with open(NOTEFILE, "r") as f:
        lines = f.readlines()

    # Clear norm.log
    with open(NORMLOG, "w") as log:
        log.write("Norminette Check Log\n====================\n")

        new_lines = []
        for line in lines:
            stripped = line.strip()
            updated = False
            for file in FILES:
                if stripped.startswith(file):
                    parts = line.split(":")
                    if len(parts) < 2:
                        new_lines.append(line)
                        updated = True
                        break
                    filename = parts[0].strip()
                    rest = parts[1].split("//")
                    status = rest[0].strip().split()

                    # preserve all flags except N, re-add N if norm OK
                    status = [s for s in status if s != "N"]
                    if has_norminette_ok(file, log):
                        status.append("N")

                    comment = "//" + rest[1] if len(rest) > 1 else ""
                    new_line = f"{filename:<15}: {' '.join(status):<10} {comment}".rstrip() + "\n"
                    new_lines.append(new_line)
                    updated = True
                    break
            if not updated:
                new_lines.append(line)

    with open(NOTEFILE, "w") as f:
        f.writelines(new_lines)

if __name__ == "__main__":
    update_note_file()
