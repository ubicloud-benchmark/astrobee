/* Copyright (c) 2017, United States Government, as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 *
 * All rights reserved.
 *
 * The Astrobee platform is licensed under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with the
 * License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#ifndef LOCALIZATION_COMMON_POSE_WITH_COVARIANCE_H_
#define LOCALIZATION_COMMON_POSE_WITH_COVARIANCE_H_

#include <localization_common/timestamped_set.h>

#include <Eigen/Geometry>

namespace localization_common {
using PoseCovariance = Eigen::Matrix<double, 6, 6>;
struct PoseWithCovariance {
  PoseWithCovariance(const Eigen::Isometry3d& pose, const PoseCovariance& covariance)
      : pose(pose), covariance(covariance) {}
  PoseWithCovariance(const Eigen::Isometry3d& pose, const PoseCovariance& covariance,
                     const TimestampedSet<PoseCovariance>& correlation_covariances)
      : pose(pose), covariance(covariance), correlation_covariances(correlation_covariances) {}

  PoseWithCovariance() {}

  Eigen::Isometry3d pose;
  PoseCovariance covariance;
  // Optional correlated covariances wrt other timestamped poses
  TimestampedSet<PoseCovariance> correlation_covariances;

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};
}  // namespace localization_common

#endif  // LOCALIZATION_COMMON_POSE_WITH_COVARIANCE_H_
