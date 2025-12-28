import re
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path


class ContactsSmokeTest(unittest.TestCase):
    def setUp(self):
        working_directory = tempfile.TemporaryDirectory()
        self.addCleanup(working_directory.cleanup)
        self.working_directory = Path(working_directory.name)

    def run_contacts(self, commands):
        result = subprocess.run(
            [executable],
            input=("\n".join(map(str, commands)) + "\n").encode("ascii"),
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            cwd=self.working_directory,
            check=True,
            timeout=10,
        )
        return result.stdout

    def test_exit_writes_empty_address_book(self):
        self.run_contacts([0])
        self.assertEqual((self.working_directory / "contact.txt").read_bytes(), b"")

    def test_add_display_and_reload(self):
        record = [1, "Avery", 32, "X", "5550100", "Oak"]
        for output in (self.run_contacts([*record, 5, 0]), self.run_contacts([5, 0])):
            self.assertRegex(output, rb"Avery\s+32\s+X\s+5550100\s+Oak")

    def test_search_edit_and_delete(self):
        self.run_contacts([1, "Avery", 32, "X", "5550100", "Oak", 0])
        found = self.run_contacts([3, "Avery", 0])
        self.assertRegex(found, rb"Avery\s+32\s+X\s+5550100\s+Oak")
        updated = self.run_contacts([4, "Avery", "Avery", 33, "X", "5550199", "Elm", 5, 0])
        self.assertRegex(updated, rb"Avery\s+33\s+X\s+5550199\s+Elm")
        deleted = self.run_contacts([2, "Avery", 5, 0])
        self.assertNotIn(b"Avery", deleted)
        self.assertEqual((self.working_directory / "contact.txt").read_bytes(), b"")


if __name__ == "__main__":
    if len(sys.argv) < 2:
        raise SystemExit("Usage: python tests/smoke.py PATH_TO_CONTACTS_EXE")
    executable = str(Path(sys.argv.pop(1)).resolve(strict=True))
    unittest.main()
