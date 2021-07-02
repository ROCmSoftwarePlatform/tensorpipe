#!/usr/bin/env python

# Copyright (c) Facebook, Inc. and its affiliates.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

import os
import sys
import argparse
import json

sys.path.append(os.path.realpath(os.path.join(
    os.path.dirname(__file__),
    os.path.pardir,
    os.path.pardir,
    'third_party')))

from hipify import hipify_python

parser = argparse.ArgumentParser(description='Top-level script for HIPifying, filling in most common parameters')
parser.add_argument(
    '--project-directory',
    type=str,
    help="The root directory of the project. (default: %(default)s)",
    required=True)

parser.add_argument(
    '--output-directory',
    type=str,
    help="The Directory to Store the Hipified Project",
    required=True)

parser.add_argument(
    '--dump-dict-file',
     type=str,
     help="The file to Store the return dict output after hipification",
     required=True)

args = parser.parse_args()

includes = [
    '*'
]

ignores = [
]

# capturing the return value which is a dict[filename]:HipifyResult
HipifyFinalResult = hipify_python.hipify(
    project_directory=args.project_directory,
    output_directory=args.output_directory,
    includes=includes,
    ignores=ignores,
    is_pytorch_extension=True)

with open(args.dump_dict_file, 'w') as dict_file:
    dict_file.write(json.dumps(HipifyFinalResult))
